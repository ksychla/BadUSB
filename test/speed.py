import time

def current_milli_time():
    return round(time.time() * 1000)

def get_wordcount(string):
    return len(string.split(" "))

def main():
    input()
    start = current_milli_time()
    result = input()
    end = current_milli_time()
    print(f"Sign count: {len(result)}")
    print(f"Word count: {get_wordcount(result)}")
    print(f"Sign/minute: {len(result) / ((end - start) / (1000 * 60))}")
    print(f"Sign/second: {len(result) / ((end - start) / (1000))}")
    print(f"Word/minute: {get_wordcount(result) / ((end - start) / (1000 * 60))}")
    print(f"Word/second: {get_wordcount(result) / ((end - start) / (1000))}")
    print(f"Time: {end - start}")


if __name__ == '__main__':
    main()
