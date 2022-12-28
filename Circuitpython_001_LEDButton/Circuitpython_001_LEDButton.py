#A full description of this module (and many others) can be downloaded at: https://eve_arduino

from digitalio import DigitalInOut, Direction, Pull
import board
import neopixel
import time

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=.2, auto_write=False)
pixels.fill((0, 0, 0))
pixels.show()

buttonA = DigitalInOut(board.BUTTON_A)
buttonA.direction = Direction.INPUT
buttonA.pull = Pull.DOWN

buttonB = DigitalInOut(board.BUTTON_B)
buttonB.direction = Direction.INPUT
buttonB.pull = Pull.DOWN

while True:
    RED = (0x10, 0, 0)
    BLUE = (0, 0, 0x10)
    BLACK = (0, 0, 0)

    if buttonA.value is True:
        for i in range(len(pixels)):
            pixels[i] = BLUE
        pixels.show()
        time.sleep(1)
    else:
        if buttonB.value is True:
            for i in range(len(pixels)):
                pixels[i] = RED
            pixels.show()
            time.sleep(1)
        else:

            for i in range(len(pixels)):
                pixels[i] = BLACK
            pixels.show()
            time.sleep(1)
