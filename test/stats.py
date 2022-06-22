import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 stats.py <file>")
        return
    with open(sys.argv[1]) as file:
        text = file.read()
    currentModifier = 0;
    allToSend = []
    toSend = []
    for i in text:
        lower = toLower(i)
        if lower in toSend or (len(toSend) > 0 and int(lower != i) != (currentModifier & 0x02) >> 1):
            allToSend.append(toSend)
            toSend = []
            currentModifier = 0
        if lower != i:
            currentModifier = 0x02
        toSend.append(lower)
    stats = [len(i) for i in allToSend]
    print(f"min: {min(stats)}")
    print(f"max: {max(stats)}")
    print(f"avg: {sum(stats)/len(stats)}")

def toLower(character):
    if character >= 'A' and character <= 'Z':
        return character.lower()
    upperCase = "!@#$%^&*()_+{}|:\"<>?~"
    lowerCase = "1234567890-=[]\\;\',./`"
    if character in upperCase:
        return lowerCase[upperCase.index(character)]
    return character


if __name__ == "__main__":
    main()
