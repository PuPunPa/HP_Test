This program iterates through the files in a given directory using c++'s filesystem to visit each file once in a nonspecific order.

Upon visit it will skip if the file is a subfolder, if not, it will print its name and size into an output .json file, program ends once every file in the directory has been visited.
