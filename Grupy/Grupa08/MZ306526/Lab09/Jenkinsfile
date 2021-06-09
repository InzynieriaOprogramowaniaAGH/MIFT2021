pipeline {
    agent any

    tools { nodejs "node"}

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
		sh 'git pull origin master'
                sh 'npm install'
            }
            post {
                success{
                    emailext(
                        attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
			subject: "Successful build in Jenkins",
                        to: 'michalzma@gmail.com'
                    )
                }
                failure{
                    emailext(
                        attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
			subject: "Build failed in Jenkins",
                        to: 'michalzma@gmail.com'
                    )
                }
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                sh 'npm install'
                sh 'npm test'
            }
             post {
                success{
                    emailext(
                        attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
			subject: "Successful Test in Jenkins",
                        to: 'michalzma@gmail.com'
                    )
                }
                failure{
                    emailext(
                        attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
			subject: "Test failed in Jenkins",
                        to: 'michalzma@gmail.com'
                    )
                }
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying..'
                sh 'docker build -t node_chat_deploy -f Dockerfile_deploy .'
                sh 'docker run -d node_chat_deploy'
            }
            post {
                success{
                    emailext(
                        attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
			subject: "Successful Deploy in Jenkins",
                        to: 'michalzma@gmail.com'
                    )
                }
                failure{
                    emailext(
                        attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
			subject: "Deploy failed in Jenkins",
                        to: 'michalzma@gmail.com'
                    )
                }
            }
        }
    }
}
