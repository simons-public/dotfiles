# .pythonrc
# -*- coding: utf-8 -*-

    import os, sys, pwd

## REPL Customization

### Colors

    DIM = "\x01\x1b[2m\x02"
    RESET = "\x01\x1B[0m\x02"
    GREEN = "\x01\x1B[32m\x02"

### PS1 and PS2 Prompts

    sys.ps1 = f"{GREEN}(python%d.%d)↝{RESET} " % (sys.version_info.major, sys.version_info.minor)

    sys.ps2 = f"{DIM}{GREEN}(python%d.%d)…{RESET} " % (sys.version_info.major, sys.version_info.minor)

### Colored tracebacks

    try:
        import traceback
        from pygments import highlight
        from pygments.lexers import get_lexer_by_name
        from pygments.formatters import TerminalFormatter

        def color_excepthook(type, value, tb):

            tbtext = ''.join(traceback.format_exception(type, value, tb))
            lexer = get_lexer_by_name("pytb", stripall=True)
            formatter = TerminalFormatter()
            sys.stderr.write(highlight(tbtext, lexer, formatter))

        sys.excepthook = color_excepthook

    except ModuleNotFoundError:
        pass
