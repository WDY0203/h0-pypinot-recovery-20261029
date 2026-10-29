from . import util
import json
import time

bbws = util.import_so('bbwebsocket')
class Transport:
    def __init__(self, myname, addr="127.0.0.1", port=2433):
        self.myname = myname
        self.conn = bbws.connect(addr, port)
        assert self.conn != 0

    def close(self):
        if self.conn != 0:
            bbws.disconnect(self.conn)
            self.conn = 0

    def __del__(self):
        self.close()

    def send(self, peername, content):
        msg = { 'from': self.myname, 'to': peername, 'content': content }
        bbws.send(self.conn, json.dumps(msg))

    def recvall(self, timeo = 5, sender = None):
        while True:
            t = time.time()
            status, data = bbws.recv_timeout(self.conn, timeo)
            if status == 0:
                try:
                    msg = json.loads(data)
                    if sender == None or msg['from'] == sender:
                        return 0, msg['from'], msg['to'], msg['content']
                except:
                    pass
                timeo = timeo - (time.time() - t)
                if timeo < 0.01:
                    return 1, None, None, None
            else:
                return status, None, None, None

    def recv(self, timeo = 5, sender = None):
        while True:
            t = time.time()
            status, data = bbws.recv_timeout(self.conn, timeo)
            if status == 0:
                try:
                    msg = json.loads(data)
                    if msg['to'] == None or msg['to'] == self.myname:
                        if sender == None or msg['from'] == sender:
                            return 0, msg['from'], msg['content']
                except:
                    if data[:8] == b'RAWSLICE' and self.myname == 'combiner':
                        cmsg = {}
                        cmsg['type'] = 'raw_slice'
                        cmsg['binary'] = data[8:]
                        return 0, 'slicer', cmsg
                    if data[:16] == b'TRADERHELPER_REQ' and self.myname == 'trader_helper':
                        cmsg = {}
                        cmsg['type'] = 'trader_helper_request'
                        cmsg['binary'] = data[16:]
                        return 0, 'trader', cmsg
                timeo = timeo - (time.time() - t)
                if timeo < 0.01:
                    return 1, None, None
            else:
                return status, None, None

class FileTransport:
    def __init__(self, myname, tofile, fromfile):
        self.myname = myname
        self.fp = open(tofile, 'w')
        self.fp_from = open(fromfile, 'r')

    def close(self):
        self.fp.close()

    def __del__(self):
        self.close()

    def send(self, peername, content):
        msg = { 'from': self.myname, 'to': peername, 'content': content }
        self.fp.write(json.dumps(msg) + "\n")

    def recvall(self, timeo = 5, sender = None):
        line = self.fp_from.readline()
        if line != '':
            msg = json.loads(line)
            if sender == None or msg['from'] == sender:
                return 0, msg['from'], msg['to'], msg['content']
            return 1, None, None, None
        else:
            return -1, None, None, None

    def recv(self, timeo = 5, sender = None):
        line = self.fp_from.readline()
        if line != '':
            msg = json.loads(line)
            if msg['to'] == None or msg['to'] == self.myname:
                if sender == None or msg['from'] == sender:
                    return 0, msg['from'], msg['content']
            return 1, None, None
        else:
            return -1, None, None
