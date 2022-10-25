import pygame
import random
pygame.init()

class DrawInformation:
    BLACK = 0, 0, 0,
    WHITE = 255, 255, 255
    GREEN = 0, 255, 0
    RED = 255, 0, 0
    GRAY = 128, 128, 128
    BACKGROUND_COLOR = WHITE

    SIDE_PAD = 100
    TOP_PAD = 150

    #Pygame window
    def __init__(self, width, height, lst):
        self.width = width
        self.height = height

        #create the pygame window
        self.window = pygame.display.set_mode((width, height))
        pygame.display.set_caption("Sorting Algroith Visualization")
        self.set_list(lst)

    #Bar attribute
    def set_list(self, lst):
        self.lst = lst
        self.min_val = min(lst)
        self.max_val = max(lst)

        #Find width of each bar
        self.block_width = round((self.width - self.SIDE_PAD) / len(lst))
        #Find the height of each bar
        self.block_height = round((self.height - self.TOP_PAD) / (self.max_val - self.min_val))
        #int divide to get a whole number
        self.start_x = self.SIDE_PAD // 2


def generate_starting_list(n, min_val, max_val):
    lst = []

    #generate list
    for _ in range(n):
        #random int including max and min val
        val = random.randint(min_val, max_val)
        lst.append(val)

    return lst

def main():
    run = True
    clock = pygame.time.Clock()

    n = 50
    min_val = 0
    max_val = 100

    lst = generate_starting_list(n, min_val, max_val)
    draw_info = DrawInformation(800, 600, lst)

    #game loop
    while run:
        clock.tick(60)

        pygame.display.update()

        #quit
        for event in pygame.event.get():
            if event == pygame.QUIT:
                run = False

    pygame.quit()

if __name__ == "__main__":
    main()






