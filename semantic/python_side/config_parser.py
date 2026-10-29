def parse(s):
    def removeComments(line) :
        # PreCond: line must be stripped
        sharpPos = line.find("#")
        if sharpPos < 0 : return line
        else : return line[:sharpPos]

    conf = {}
    for line in s.split('\n'):
        content = removeComments(line.strip())
        tokens = list(map(lambda x: x.strip(), content.split('=')))
        if len(tokens) != 2:
            continue
        elif tokens[0] == 'punish':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'max_turn':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'trans_fee':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'min_awgt':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'max_awgt':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'l_ind_awgt':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'u_ind_awgt':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'l_fexp_expo':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'u_fexp_expo':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'target_cash_initial':
            conf[tokens[0]] = float(tokens[1])
        elif tokens[0] == 'max_wgt':
            conf[tokens[0]] = float(tokens[1])
        elif len(tokens[0]) != 0:
            conf[tokens[0]] = tokens[1]
        else:
            continue
    return conf
