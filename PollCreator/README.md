# PollCreator ☑

This is a small little Windows program written in C++ that allows a person to create a poll, or participate in an existing poll.

There are 2 modes to the app:
1. Create a Poll 
2. Participate in the existing Poll 

When option (1) is taken, the app will allow the user to interactively create a poll that will be saved into a `db.json` file. 
When option (2) is taken, the app will load the existing `db.json` file and allow the user to participate in a poll. 

Currently, the **limitation** is that only one active poll can exist at a time as the program always assumes a `db.json` file. 
Having, and managing multiple polls is beyond the scope of this project.

## How to Build

Use Visual Studio to compile the C++ project. It is a very standard project so there should not be any issues. 

## How to Run

This program has been tested on:
* Windows 10
* Windows 11

Possible Compatible OS:
* Windows 7
* Windows 8

You can run the app and go into its interactive mode to show which mode to execute by just running `PollCreator.exe`. But you can also run the `.bat` files (yes it is Windows) to go directly into the specific mode. The `.bat` files execute `PollCreator.exe` with `args` like this:

```
Create poll:
    PollCreator.exe 1

Participate poll:
    PollCreator.exe 2
```

## Feedback/Contact

Direct it to: `urbanspr1nter@gmail.com`