#!/usr/bin/env python
# 写一个git的py
import os
import sys
import subprocess

def git_push():
    path = os.path.abspath(os.path.dirname(__file__))
    os.chdir(path)
    os.system('git add .')
    os.system('git commit -m "%s"' % sys.argv[1])
    os.system('git push -u origin main')
    print('push success')

if __name__ == '__main__':
    git_push()