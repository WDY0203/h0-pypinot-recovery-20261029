def import_so(name):
    import sys, os
    if sys.version_info[0] < 3:
        import imp
        load_dynamic = imp.load_dynamic
    else:
        import importlib
        def load_dynamic(module, path):
            spec = importlib.util.spec_from_file_location(module, path)
            mod = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(mod)
            return mod
    path = os.path.join(os.path.dirname(__file__), name + '.so')
    try:
        import zipfile, tempfile
        zippath = os.path.split(os.path.split(__file__)[0])[0]
        with zipfile.ZipFile(zippath) as f:
            path2 = path[len(zippath) + 1:]
            with f.open(path2) as g:
                with tempfile.NamedTemporaryFile(dir='/dev/shm', suffix='.so') as h:
                    h.write(g.read())
                    h.flush()
                    return load_dynamic(name, h.name)
    except:
        sys.stderr.write('Warning: use external dynamic object: ' + name + '\n')
        return load_dynamic(name, path)
