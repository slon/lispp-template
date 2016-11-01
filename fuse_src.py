import sys
import os
import os.path
import re

INCLUDE_ONCE = set()
INCLUDE_RE = re.compile(r'#include [<"](.+)[>"]')

def fuse_sources(dir, name):
    for line in open(os.path.join(dir, name)):
        if line.startswith("#pragma once"):
            continue
        
        m = INCLUDE_RE.match(line)
        if m:
            include_name = m.group(1)
            if include_name.startswith("lispp/"):
                include_name = include_name.split("/")[1]

            if os.path.exists(os.path.join("lispp", include_name)):
                if include_name not in INCLUDE_ONCE:
                    INCLUDE_ONCE.add(include_name)
                    fuse_sources("lispp", include_name)
                continue

        sys.stdout.write(line)

if __name__ == "__main__":
    fuse_sources(".", "main.cpp")
    for fname in os.listdir("lispp"):
        if fname.endswith(".cpp"):
            fuse_sources("lispp", fname)
