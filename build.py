import sys

ARG_COUNT = 2
TGT_FILE  = 1

src_prefix = 'src'
inc_prefix = 'include'
tests     = 'tests'
dirs      = 'Linked-Lists,Queues,Stacks'
dirs_l    = dirs.split(',')

class BuildTarget:
    def __init__(self):
        None

def usage():
    print("Usage: [Target File]")
    None

def targetize():
    None

def build():
    None

def main():

    if len(sys.argv ) != ARG_COUNT:
        usage()
        sys.exit(0)
    else:
        print("Building: " + sys.argv[TGT_FILE])



if __name__ == '__main__':
    main()
