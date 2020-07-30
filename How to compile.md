# How to compile

## Setup conda environment
1. [Install miniconda](https://docs.anaconda.com/anaconda/install/).
2. [Create](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#creating-an-environment-with-commands) conda virtual environment.
3. [Initialize and activate](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#activating-an-environment) conda environment in terminal.

Sample commands:
```
$ conda create --name conda_venv python=3.6
$ conda init
# now open a new terminal window
$ conda activate conda_venv
```

## Install dependency packages
```
$ conda install -y -c sebp --file requirements.txt
$ conda install -y gxx_linux-64
```
