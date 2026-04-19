import sys
from . import getcode

def main():
    if len(sys.argv) < 3:
        print("Usage: ajay <algorithm> <py/c>")
        return

    name = sys.argv[1]
    lang = sys.argv[2]

    result = getcode(name, lang)
    print(result)

if __name__ == "__main__":
    main()