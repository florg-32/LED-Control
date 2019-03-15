import eel
from serial import Serial

def by(n):
    return n.to_bytes(1, 'big')
 
@eel.expose
def setColor(color):
    s.write(by(0))
    s.write(by(color['r']))
    s.write(by(color['g']))
    s.write(by(color['b']))

s = Serial("COM3")
eel.init("gui")
eel.start("index.html", block=False)

print("!")
while True:
    eel.sleep(10)