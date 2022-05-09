# Indie Studio
This project aims to be a bomberman clone using the raylib graphical library.

# Compilation:

    cmake -B build
    cmake --build build

# Pull requests:
A pull request needs to be made before merging on dev and main.

# Commit norm:
Verbe conjugué en majuscule: action
Examples -> ADDING: run function in Core.cpp
         -> MODIFYING: Entity class in Entity.hpp

# Commits:
To undo last commit and to restore file content to the prevous commit:
    git reset --hard HEAD^
Same thing but keeping your changes:
    git reset HEAD^
To undo X last commits:
    git reset (--hard) HEAD~X
Be careful, the following command deletes all your local commits on the current branch:
    git reset (--hard)