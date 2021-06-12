## Lab 7: Pipeline CI/CD - basics & testing.

### Task

1. *your "source of truth" - place (copy) all source files (environment runtime scripts, Dockerfile, docker-compose.yaml, Jenkinsfile from these classes too etc.) in the repository InzynieriaOprogrammingAGH/MIFT2021.git.*

*Note: Maintain the following folder order:
<your folder>/<technology name>/<files> - e.g.: "KM123456/Docker/Dockerfile_rockechat_build"*

*Note: use meaningful declarative names, so that the file name itself indicates what it is for.*

*2 From your CI/CD pipeline plan created on Lab06, select the point(s) that are responsible for "Running fast and reliable testing."*

*2.1 Next, create a Jenkinsfile and place it in the messenger repo (this is not the same repo as for the scripts in point 1!).*

*2.2 (Optional) Note that you may want to do a "fork" on the original repo.*

*2.3 In the Jenkinsfile, create a new Jenkins pipeline (example here: [https://www.jenkins.io/doc/book/pipeline/jenkinsfile/](https://www.jenkins.io/doc/book/pipeline/jenkinsfile/)) , and in it, in the "stages" section, a new "stage('Test')".*

*2.4 Inside the Jenkinsfile in the "stage('Test')" section, script the test runs for the application from point 2.1. 2.1 - make sure that:*

- *the log with the effects of testing should go to the user ('notification of results')*
- *detect and handle the case when
-- tests succeed (100%)
-- tests fail (< 100%)*
1. *execute and demonstrate an example of executing these tests using Jenkinsfile.*
2. *upload Jenkinsfile to the repo from point 1.*

### What I have done:

- firstly forked the node-chat-app repository to clone it in my own IDE and add the Jenkinsfile (and check it into source control in my personal GitHub account)
- created a new Slack organization where the only person is me
- installed jenkins plugin: [Slack Notification](https://plugins.jenkins.io/slack/)
- configured the Jenkins integration with Slack in Slack settings (followed [this tutorial)](https://jenkinsplayground.slack.com/apps/new/A0F7VRFKN-jenkins-ci)
- created the following Jenkinsfile (followed the [Jenkins tutorial for builidng a Node.js/React app](https://www.jenkins.io/doc/tutorials/build-a-node-js-and-react-app-with-npm/))

```jsx
pipeline {

    agent {
        docker {
            image 'node:latest' 
            args '-p 3000:3000' 
        }
    }

	environment {
        CI = 'true' 
    }

  stages {
    stage('Build') {
      steps {
        sh "npm install"
      }
    }
    stage('Test') {
      steps {
        sh 'npm test'
      }
    }
  }
    post {
    
    	always {
    	    echo 'Finished!'
    	}
    	
    	success {
            slackSend (color: '#00FF00', message: "SUCCESSFUL: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
            echo 'Success!'
    	}
    	
        failure {
            echo 'Failure!'
            slackSend (color: '#FF0000', message: "FAILED: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
    }
}
```

**Jenkinsfile notes:**

- in `agent` section's `docker` parameter:
    - the image section downloads the latest version of node image from dockerhub and runs this image as a separate container
        - it's downloaded only once, then Jenkins only need to run a new container from previously downloaded Node image.
    - in this scenario I have:
        - separate Jenkins and Node containers running locally in Docker.
        - **the Node container becomes the agent that Jenkins uses to run the Pipeline project.**
            - However, **this container is short-lived** - **its lifespan is only that of the duration of the Pipeline’s execution.**
    - `args` parameter makes the Node container (temporarily) accessible through port 3000.
- the *Build* stage ensures that there are downloaded all dependencies required to run the node chat application (and the tests)
- the *Test* simply run `npm test` to check if the app works correctly
- for the sake of testing, the notification is sent to slack channel when the build is successful and when it is not
- When the npm test command detects the environment variable CI with a value of true, then this command is run in "non-watch" (i.e. non-interactive) mode. In "watch" mode, npm test expects user input, which can pause running builds of CI/CD applications indefinitely. (TODO: Check if this is the case in my test script.)

**Comments:**

- when trying to make it work I installed the following plugins in Jenkins
    - NodeJS Plugin - *executes NodeJS script as a build step.*
    - Pipeline NPM Integration Plugin - *This plugin provides integration with Pipeline, configures npm environment to use within a pipeline job by calling sh npm or bat npm. The select npmrc will be configured and placed in the workspace prior to the build in order to take precedence over any user or global npmrc*
- finally I didn't made it work, so I decided to download new node image from dockerhub and run the app on this image-based container
- TODO: the above steps must be analysed - probably I will fully understand what is going on here when preparing next laboratory classes.

**Jenkins project**

- in Jenkins followed steps: New item → Pipeline → Pipeline script from SCM → pasted the link to forked node-chat-app github repo → Selected git → Saved