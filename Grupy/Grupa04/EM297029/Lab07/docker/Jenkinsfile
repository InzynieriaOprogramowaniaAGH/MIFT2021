pipeline {
    agent none
    environment {
        TEST_PREFIX = "test-IMAGE"
        TEST_IMAGE = "${env.TEST_PREFIX}:${env.BUILD_NUMBER}"
        TEST_CONTAINER = "${env.TEST_PREFIX}-${env.BUILD_NUMBER}"
        REGISTRY_ADDRESS = "my.registry.address.com"

        SLACK_CHANNEL = "#deployment-notifications"
        SLACK_TEAM_DOMAIN = "MY-SLACK-TEAM"
        SLACK_TOKEN = credentials("slack_token")
        DEPLOY_URL = "https://deployment.example.com/"

        COMPOSE_FILE = "docker-compose.yml"
        REGISTRY_AUTH = credentials("docker-registry")
        STACK_PREFIX = "my-project-stack-name"
    }
    stages {
        Stage('Build'){
            steps{
		sh 'docker-compose up'

            }
	}
	Stage('Test'){
	    steps{
                sh -c '.\code\wait.sh server:1234 -- echo READY && node .\code\client.js'
	    }
 	}
    }
    post {
    failure {
        mail to: 'emroz@student.agh.edu.pl',
             subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
             body: "Something is wrong with ${env.BUILD_URL}"
    }
    success {
            echo 'I succeeded :D'
    }
}
}

command: 