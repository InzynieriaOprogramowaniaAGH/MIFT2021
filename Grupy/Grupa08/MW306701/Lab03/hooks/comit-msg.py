#!/usr/bin/python
import sys

def main():
    with open(sys.argv[1], "r") as fp:
	commitMessage = fp.readlines()

	if commitMessage[0].startswith("MW306701"):
	    print("Dobry commit message")
	    sys.exit(0)

	else:
	    print("Bledna nazwa")
	    sys.exit(1)

if __name__ == "__main__":
    main()
