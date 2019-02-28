
def filt(a):
  if a.islower():
    return "0"
  else:
    return "1"


f = open('q22')
lines2 = f.readlines()  # 1行毎にファイル終端まで全て読む(改行文字も含まれる)
f.close()
for line in lines2:
  print(','.join(list(map(filt, line))))

