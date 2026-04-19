import sys
from . import getcode

def main():
    if len(sys.argv) < 3:
        print("Usage: ajay <algorithm> <py/c>")
        print("Example: ajay dijkstra py")
        return

    name = sys.argv[1]
    lang = sys.argv[2]

    print(getcode(name, lang))