# Indie Studio
This project aims to be a bomberman clone using the raylib graphical library.

# Compilation:
    cmake -B build
    cmake --build build

    For debugging:
    cmake -DCMAKE_BUILD_TYPE=Debug build
# Language:
Use english EVERYWHERE !

# Pull requests:
A pull request needs to be made before merging on dev and main.
To create a pull request:
    - Go on https://github.com/iDommel/indieStudio
    - Click on the "Pull requests" tab -> "New pull request"
    - Select dev as "base:" and the branch you want to merge as "compare:"
    - Click on "Create pull request"
    - Enter a title and a description for your pull request
    - Select 2 reviewers fitted to review your code (Reviewers tab is at the right of the description)
    - Click again on "Create pull request" => Your pull request is created
    - If one or more reviewers asked for changes, just push your changes and your pull request will update accordingly
    - Once your pull request is validated by all the reviewers you can click on "Merge pull request" => Your pull
    request is merged

# Commit norm:
Conjugated verb in preterit form and in upper case: action
Examples -> ADDED: run() function in Core.cpp
         -> MODIFIED: Entity class in Entity.hpp

# Commits:
To undo last commit and to restore file content to the prevous commit:
    git reset --hard HEAD^
Same thing but keeping your changes:
    git reset HEAD^
To undo X last commits:
    git reset (--hard) HEAD~X
Be careful, the following command deletes all your local commits on the current branch:
    git reset (--hard)

# Namespace and Class nomenclature
When encapsulating Class of raylib don't forget to use "indi" namespace