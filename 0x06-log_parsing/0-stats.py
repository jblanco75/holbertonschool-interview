#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""


from sys import stdin


def statPrinter(fileSize, codeBook):
    """Prints file size and codes"""
    print("File size: {}".format(fileSize))
    for code in sorted(codeBook.keys()):
        if codeBook[code] != 0:
            print("{}: {}".format(code, codeBook[code]))


lineCount = fileSize = currentCode = 0
codeBook = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}

try:
    for line in stdin:
        lineCount += 1
        currentLine = line.split()

        if currentLine[-1].isnumeric():
            fileSize += int(currentLine[-1])

        if len(currentLine) > 2 and currentLine[-2] in codeBook:
            codeBook[currentLine[-2]] += 1

        if lineCount % 10 == 0:
            statPrinter(fileSize, codeBook)

    statPrinter(fileSize, codeBook)

except (KeyboardInterrupt):
    statPrinter(fileSize, codeBook)
