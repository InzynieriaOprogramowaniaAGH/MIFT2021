## Lab 8: Pipeline CI/CD - automatic build.

### Task

1. *extend Jenkinsfile from Lab07 with a new stage("Build") - documnetation with available commands is here: [https://www.jenkins.io/doc/book/pipeline/jenkinsfile/](https://www.jenkins.io/doc/book/pipeline/jenkinsfile/).*
2. *in stage("Build") make sure that:*
- *the latest source code version is downloaded from the repository*
- *the program is built*
- *the user is notified of both the success and failure of the build stage.*
1. *make sure that after a successful build the stage("Test") is run, but after a failed build this does not happen.*
2. *Write a git "post-commit" hook ([https://www.git-scm.com/docs/githooks#_post_commit](https://www.git-scm.com/docs/githooks#_post_commit)) for the messaged repository that displays the message "This is a commit hook that will someday run Pipeline after each new commit".*

### Notes

- changed a little bit the Jenkinsfile from the previous class
- in "Build" stage the program downloaded from the repository is built and all necessary dependencies are installed
- in this version of Jenkinsfile notifications to slack are send both when building and testing stage is executed
- when the Build stage is not successful the testing stage is not executed (screenshot attached)

```groovy
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
      post {
        success {
          echo 'Build success!'
          slackSend (color: '#00FF00', message: "Build success: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
        failure {
          echo 'Build failure!'
          slackSend (color: '#FF0000', message: "Build failure: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
      } 
    }

    stage('Test') {
      steps {
        sh 'npm test'
      }  
      post {
        success {
          echo 'Tests passed!'
          slackSend (color: '#00FF00', message: "Tests passed: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
        failure {
          echo 'Tests failure!'
          slackSend (color: '#FF0000', message: "Tests failed: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
      }
    }
  }
}
```

- then created a *post-commit* hook and placed it inside node chat app repository's .git folder