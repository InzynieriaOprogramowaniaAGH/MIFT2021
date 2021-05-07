FROM app_build:latest

WORKDIR ./deltachat-desktop

RUN npm test
