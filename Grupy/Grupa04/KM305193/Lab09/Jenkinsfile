pipeline 
{
    agent any 
    triggers
    {
        githubPush()
    }
    stages 
    {
        stage('Build') 
        { 
            steps 
            {
                sh 'git pull origin master'
                sh 'npm install'
                sh 'npm run build'
            }
            post 
            {
                failure 
                    {
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'kmat962@gmail.com',
                    subject: "Build failure ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                    }
                success 
                    {
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'kmat962@gmail.com',
                    subject: "Build positive ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                    }
            }
        }
        stage('Test') 
        { 
            steps 
            {
                echo 'Testing'
                sh 'npm run test'
            }
            post 
            {
                failure 
                    {
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'kmat962@gmail.com',
                    subject: "Test failure ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                    }
                success 
                    {
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'kmat962@gmail.com',
                    subject: "Test positive ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                    }
            }           
        }
        stage('Deploy')
        {
        	steps
        	{
        		echo 'Deploying'
        		sh 'docker build -t deploy -f Deploy-dockerfile .'
        	}
        	post
        	{
        	failure 
                    {
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'kmat962@gmail.com',
                    subject: "Deploy failure ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                    }
                success 
                    {
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'kmat962@gmail.com',
                    subject: "Deploy positive ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                    }
        	}
        }
    }
}
