class q4:
    str = ""
    def get_String(self):
        self.str = input('enter a string: ')
    def print_String(self):
        print(self.str.upper())
        return
obj = q4()
obj.get_String()
obj.print_String()