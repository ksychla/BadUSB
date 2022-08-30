import sys, tty, termios, time

class _Getch:
    """Gets a single character from standard input.  Does not echo to the
screen."""
    def __init__(self):
        self.impl = _GetchUnix()

    def __call__(self): return self.impl()


class _GetchUnix:
    def __init__(self):
        pass

    def __call__(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch

def current_milli_time():
    return round(time.time() * 1000)

def get_word_count(string):
    return len(string.split(" "))

if __name__ == '__main__':
    getch = _Getch()
    start = 0
    times = []
    text = ""
    for i in range(1, 5001):
        l = getch()
        if i == 1:
            start = current_milli_time()
        if i % 100 == 0:
            end = current_milli_time()
            word_count = get_word_count(text)
            times.append({"Char count": i, "Word count": word_count, "Time": end - start, "char/sec": i/((end - start)/1000), "word/sec": word_count/((end - start)/1000)})
        text += l
    input()
    print(f"Word count: {get_word_count(text)}")
    print(f"Times: {times}")
