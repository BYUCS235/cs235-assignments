# Cloning This Repository

You are not required to use Git to manage the homework files and instructions. You may simply download the files using the associated buttons and links in GitHub.

However, if you are interested in trying, these instructions might be helpful.

**IMPORANT**

Do **not** publish your work to the public internet. If you clone this repo and choose to `push` your work to GitHub, you must push to a *private* repository. Publishing your work in a manner that other students can find it will be considered cheating. 

## Step 1: Clone the repository

To get started, you'll first need to clone the class git repository. This will create a local copy of the repository on your computer.

- Open your terminal or Command Prompt.
- Navigate to the folder you would like to store the local copy of the class repository.
- Run the following command (replace <repository_url> with the actual URL of the course repository):

```
   git clone <repository_url>
```

This will create a new folder with the repository name containing all the starter files and instructions.

## Step 2: Commit your changes
As you work on your assignments, you can save a backup of your work by committing your changes.

- Navigate to your repository folder in the terminal or Command Prompt.
- Check the status of your changes using `git status`. This will show you any new, changed, or deleted files.
- Add the changed files to the staging area using `git add <file_name>` or `git add .` (to add all changes).
- Commit your changes using `git commit -m "Your commit message"` (Replace "Your commit message" with a brief description of the changes you made).

Your changes are now saved in your local repository.

You can also see and commit your changes in your IDE. 

## Step 3: Pull updates

To receive any updates to the instructions or starter files from the course repository, you'll need to pull the latest changes.

- Before pulling, make sure you have committed your current work following Step 2. This will help to avoid conflicts during the pull process.
- Run `git pull` to fetch and merge the latest changes from the remote repository.

If there are any conflicts between your local changes and the updates, Git will notify you. To resolve the conflicts, we recommend you use the *resolve conflicts* feature in your IDE.

After resolving conflicts, your repository will be up to date with the latest course materials.



