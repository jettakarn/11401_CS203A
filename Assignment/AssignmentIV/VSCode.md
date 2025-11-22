# Visual Studio and GitHub Setup Guide
## Prerequisites
### Install VS Code
- Option 1 - Use apt (Recommended)
```bash
sudo apt update
sudo apt install software-properties-common apt-transport-https wget -y
wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
sudo apt update
sudo apt install code
```

- Option 2 - Via Snap (I use this)
```bash
sudo snap install code --classic
```

### Install Git
- Installation
```bash
sudo apt update
sudo apt install git
```

- Configuration
```bash
git config --global user.name "Your Name"
git config --global user.email "youremail@example.com"
```

- Check Git Version
```bash
git --version
```
## Extensions
### GitHub Pull Requests and Issues
- This extension allows you to
* Create, review, and manage pull requests
* Manage GitHub issues
* View PR changes inside VS Code

- Install through UI:
1. Open VS Code
2. Press Ctrl+Shift+X
3. Search: GitHub Pull Requests and Issues
4. Click Install

## Sign-In to GitHub from VS Code
1. Press **Ctrl+Shift+P**
2. Type: **GitHub: Sign in**
3. Choose: **Sign in with GitHub**
4. A browser window opens → Authorize VS Code
5. Return to VS Code; you should see a confirmation

## Clone the Repo
- Using Command Palette
1. Press **Ctrl+Shift+P**
2. Type: **Git: Clone**
3. Paste your repository URL
4. Choose a folder to store the repo
5. When VS Code asks “Open the cloned repository?” → click **Open**
```bash
https://github.com/jettakarn/11401_CS203A.git
```
## Git Workflow
- Stage + Commit Changes
1. Go to **Source Control** panel (Ctrl+Shift+G)
2. Click **+** to stage changes
3. Enter a commit message
4. Click **Commit**

- Push to GitHub
Click **Sync Changes**, or run:
```bash
git push
```

## Creating & Managing Pull Requests
- Create a Pull Request
1. Open the **GitHub Pull Requests** panel
2. Click **Create Pull Request**
3. Select:
    * Source branch
    * Target branch
4. Add title + description
5. Submit PR

- Review Pull Requests
* View PR diff inside VS Code
* Add comments inline
* Approve / request changes