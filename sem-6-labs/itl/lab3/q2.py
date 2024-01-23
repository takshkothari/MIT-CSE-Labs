import sys

def reverse(fr,fw):
    f1 = open(fr,'r')
    f2 = open(fw,'w')
    text = f1.read()
    text_w = text[::-1]
    f2.write(text_w)
    f1.close()
    f2.close()

def main():
    fr = input("file to read: ")
    fw = input("file to write: ")
    reverse(fr,fw)

if __name__ == '__main__':
    main()
