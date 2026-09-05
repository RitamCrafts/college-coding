# 📚 Syllabus Coding Repository

This repository is for practicing syllabus topics together and sharing code.

## 👥 Branches

Each person has their own branch:

```text
main
├── Ritam
├── Anish
└── Souvik
```

**Do your work only on your own branch.**

* Ritam → `Ritam`
* Anish → `Anish`
* Souvik → `Souvik`

Do not work directly on `main`.

---

# 🚀 First-Time Setup

You only need to do this once.

### 1. Install Git

Download Git from:

https://git-scm.com/downloads

### 2. Clone the repository

Open Terminal / PowerShell / Git Bash and run:

```bash
git clone <REPOSITORY-URL>
```

Then enter the repository:

```bash
cd <REPOSITORY-NAME>
```

This downloads the **entire repository** to your computer.

### 3. Check available branches

```bash
git branch -a
```

You should see something similar to:

```text
* main
  remotes/origin/main
  remotes/origin/ritam
  remotes/origin/anish
  remotes/origin/souvik
```

### 4. Switch to your branch

#### Ritam

```bash
git switch ritam
```

#### Anish

```bash
git switch anish
```

#### Souvik

```bash
git switch souvik
```

Check which branch you're currently on:

```bash
git branch
```

The branch with `*` is your current branch.

---

# 🔄 Every Time You Start Coding

First make sure you're on **your own branch**:

```bash
git switch YOUR-NAME
```

Then get the latest version of your branch:

```bash
git pull
```

Now start coding.

---

# 💾 Saving Your Work

After writing your code:

### 1. Check what changed

```bash
git status
```

### 2. Add your changes

```bash
git add .
```

### 3. Commit

```bash
git commit -m "Added stack implementation"
```

### 4. Push to YOUR branch

```bash
git push
```

Your code is now on GitHub in **your branch**.

---

# ⚠️ IMPORTANT

### ❌ Don't do this:

```bash
git switch main
```

and start coding there.

### ❌ Don't push to main:

```bash
git push origin main
```

### ✅ Do this:

```bash
git switch YOUR-NAME
git pull
```

Then code, commit and:

```bash
git push
```

---

# 🔀 Getting Changes From `main`

If new/common files or updates have been added to `main` eg after semesters or randomly, you can bring them into your branch.

First:

```bash
git switch main
git pull
```

Then switch back to your branch:

```bash
git switch YOUR-NAME
```

Merge the latest `main` into your branch:

```bash
git merge main
```

If there are conflicts, **don't panic**. Ask for help before deleting or replacing files.

---

# 📁 Where Should I Put My Code?

Put your code inside your own folder.

Example:

```text
Ritam/
    DSA in C/
        Stack/
        Queue/
        Linked List/

Anish/
    ...

Souvik/
    ...
```

Do not modify another person's folder unless you have discussed it with them.

---

# 🧠 Simple Workflow

Remember this:

```text
        Clone (first time)
               ↓
       Switch to YOUR branch
               ↓
             Pull
               ↓
            Code
               ↓
          git add .
               ↓
            commit
               ↓
            push
               ↓
          GitHub YOUR branch
```

### Golden Rule

> **Pull before you code. Push after you code. Always check which branch you're on.**

Your branch is your workspace. `main` is the central/official version updated from time to time(eg after semesters)
