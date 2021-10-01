from tkinter import *
from tkinter.ttk import *

from time import strftime
sws = Tk()
sws.title("Clock")
def time():
    string= strftime('%H:%M:%S %p')
    label.config(text=string)
    label.after(1000, time)

label=Label(sws, font=("",35),background="blue",foreground="pink")
label.pack(anchor='center')
time()

mainloop()


