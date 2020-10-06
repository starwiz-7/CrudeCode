# auth: starkizard
# representing the chess board as columns, diagonal 1, diagonal 2, 
# diagonal 1s value is r+c throughtout, diagonal 2 value is r-c+7 (check it out!)
# Putting queen row by row, so i don't need to check for previous rows, that's why didn't put it
# Putting all the reserved squares in a 2d array
# 
# Used backtracking, putting a queen in row by row, checking coloumn from 0 to 7. the value would be False, if it's not attacked already, and True if it is
# recurse to next row
# if row becomes equal to 8, increment the counter for a valid solution.

ways=0
col,diag1,diag2=[],[],[]
reserved=[[False for i in range(8)] for j in range(8)]

def search(r):
    global ways
    if r==8:
        ways+=1
        return
    
    for c in range(8):
        if(col[c] or diag1[r+c] or diag2[r-c+7] or reserved[r][c]):
            continue
            
        col[c]=diag1[r+c]=diag2[r-c+7]=True
        search(r+1)
        col[c]=diag1[r+c]=diag2[r-c+7]=False

def main():

    for i in range(16):
        col.append(False)
        diag1.append(False)
        diag2.append(False)
   
   for i in range(8):
        row=input()
        for j in range(len(row)):
            if row[j]=="*":
                reserved[i][j]=True


    search(0)
    print(ways)
