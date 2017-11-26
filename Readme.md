# Photoneo bin-picking web interface

## Requirements

* Python 3.5
* Docker
* yarn

## Installation

[Get Docker CE for Ubuntu](https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/).

When running for the first time, log in to the Docker Cloud:
```sh
$ docker login
```

Pull the `photoneo/binpicking` docker image:
```sh
$ docker pull photoneo/binpicking
```

Clone the git repository and all of its submodules via SSH:
```sh
$ git clone --recursive git@github.com:photoneo/binpicking.git
```
or via HTTPS:
```sh
$ git clone --recursive https://github.com/photoneo/binpicking.git
```

Submodule uses HTTPS by default (as defined in `.gitmodules`). If you want to use SSH, you can locally change the URL for the submodule:
```sh
$ git config submodule.ros_web_visualizer_data.url git@github.com:photoneo/ros_web_visualizer_data.git
```

Enter the project folder:
```sh
$ cd binpicking/web
```

Install virtual environment (optional):
```sh
$ python3 -m venv .
$ source ./bin/activate
```

Create local settings file:
```sh
$ cp config/settings/.env.keep config/settings/.env
```

Setup `catkin_ws` in your home directory:
```sh
$ mkdir -p ~/catkin_ws/src
$ cp -r ../ros_web_visualizer_data ~/catkin_ws/src
```

Compile `catkin_ws` via tools contained in the `photoneo/binpicking` docker image:
```sh
$ docker run -it --rm -v ~/catkin_ws:/home/controller/catkin_ws photoneo/binpicking /bin/bash
controller@<container-id> $ cd ~/catkin_ws && catkin_make
controller@<container-id> $ exit
```

Install frontend dependencies:

```sh
yarn install
```
[yarn installation instructions](https://yarnpkg.com/lang/en/docs/install/)

We use [GULP.js](https://gulpjs.com/) as task runner. If you need to run gulp manually, you can run it from yarn dependencies via:
```sh 
./node_modules/gulp/bin/gulp.js [task name]
```
or you can install it locally.

### Development environment

Edit the local settings file (`.env`) and set ``DJANGO_SETTINGS_MODULE=config.settings.dev``.
```sh
$ pip install -r requirements/dev.txt
$ python manage.py migrate
$ python manage.py loaddata dev
$ unzip webconfig/fixtures/upload-dev.zip
$ python manage.py runserver
```

Credentials for the superuser: `admin@example.com / resalresal`

### Production environment

Edit local settings file (`.env`) and set ``DJANGO_SETTINGS_MODULE=config.settings.production``.

```sh
$ pip install -r requirements/production.txt
$ python manage.py check --deploy
$ python manage.py migrate
$ python manage.py createsuperuser
```

## Development

### Code and docs guidelines

Please follow the [Style Guide for Python Code](https://www.python.org/dev/peps/pep-0008/)
and the [numpydoc](https://github.com/numpy/numpy/blob/master/doc/HOWTO_DOCUMENT.rst.txt).

### Version control with git

Main principles:
* master branch is (mostly) stable
* development is done on "feature" (or "topic") branches
* ideal rule: one "feature" = one commit
* avoid merge commits, rebase before merge
* tags for releases

#### Feature branch
A "feature" or "topic" branch should concentrate on solving one specific task.
It can be a bug fix, a new feature, or new documentation. This should help
to better split the work for multiple developers and to create less merge
conflicts when integrating the work into the master.

Lifecycle:

1. create a feature branch from the actual master
```sh
$ git checkout master
$ git pull origin master
$ git checkout -b <feature_branch>
```

2. continously commit related changes, rebase to the actual master
```sh
$ git add ...
$ git commit -m ...
$ git pull --rebase origin master
```

3. when finished, make sure all tests are passing
```sh
$ py.test
```
do not forget to install also testing deps:
```
$ pip install -r requirements/testing.txt
```

4. push the branch to github and create a pull request
```sh
$ git push --set-upstream origin <feature_branch>
```

5. when finished, squash commits to match the rule "one feature = one commit", reword commit messages
```sh
$ git rebase -i ...
```

6. merge to master
```sh
$ git checkout master
$ git merge <feature_branch>
$ git push
```
