// This step should not normally be used in your script. Consult the inline help for details.
withDockerContainer('test') {
    // some block
}

// This step should not normally be used in your script. Consult the inline help for details.
withDockerRegistry(credentialsId: 'DOCKERHUB', url: 'registry.com') {
    // some block
}