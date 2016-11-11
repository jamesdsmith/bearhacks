from drawing import *
from math import *
from PIL import Image, ImageDraw
from IPython.display import Image as img
from IPython.display import display

class Drawing:
    def __init__(self, w, h):
        self.width = w
        self.height = h
        self.size = 4
        self.bgcolor = (1,1,1)
        self.angle = -90
        self.pen_state = 0
        self.pos = [w/2,h/2]
        self.image = Image.new('RGBA', (self.width, self.height))
        self.draw = ImageDraw.Draw(self.image)
        self.color = [255, 0, 0]
        self.pen_width = 2

d = Drawing(400,400)

def new_drawing(w=400, h=400):
    Drawing.__init__(d, w, h)

def show():
    display(d.image)

def pen_down():
    d.pen_state = 1

def pen_up():
    d.pen_state = 0

def pixel_pos(pos):
    return (round(pos[0]), round(pos[1]))

def set_pixel(x, y):
    d.draw.point((x, y), tuple(d.color))

def forward(dist):
    newpos = [d.pos[0] + cos(d.angle * pi / 180)*dist, d.pos[1] + sin(d.angle * pi / 180)*dist]
    if d.pen_state == 1:
        d.draw.line([pixel_pos(d.pos), pixel_pos(newpos)], tuple(d.color), d.pen_width)
    d.pos[0] = newpos[0]
    d.pos[1] = newpos[1]

def set_width(num):
    d.pen_width = num

def goto(x, y):
    d.pos[0] = x
    d.pos[1] = y

def turn_right(deg):
    d.angle = (d.angle + deg) % 360

def turn_left(deg):
    turn_right(-deg)

def set_color(r, g, b):
    d.color[0] = round(r)
    d.color[1] = round(g)
    d.color[2] = round(b)

def get_color():
    return d.color[0], d.color[1], d.color[2]
 
