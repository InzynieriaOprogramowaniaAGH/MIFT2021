var chai = require('chai');
var chaiHttp = require('chai-http');
var url = 'http://localhost:3000';
chai.use(chaiHttp);

var expect = chai.expect;

describe('Server', function (){
  
  it('Should succesfully get the home page', function (){
    return chai.request(url)
    .get('/')
    .then(function (res) {
      expect(res).to.have.status(200);
    }) 
    .catch(function (err) {
      return Promise.reject(err);
    });
  });
  
  it('Should return an html file as default', function () {
    return chai.request(url)
    .get('/')
      .then(function (res) {
        expect(res).to.be.html;
      })
      .catch(function (err) {
        return Promise.reject(err);
      });
  });
    
});