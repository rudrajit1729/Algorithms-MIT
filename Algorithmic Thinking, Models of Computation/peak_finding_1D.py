from random import randint

def generate():
    size = randint(0, 10001)
    #size = 10000000
    l = [randint(0,100) for x in range(int(size))]
    return (int(size), l)

def solve(A, lb, ub):
    mid = (lb+ub)//2
    while(lb<ub):
        mid = (lb+ub)//2
        if A[mid]<A[mid-1]:
            ub = mid-1
        elif A[mid]<A[mid+1]:
            lb = mid+1
        else:
            return mid
    return mid

def main():
    size, A = generate()
    
    print(size)
    #print(A)
    pos = solve(A, 0, size - 1)
    print("--------------------------Result--------------------------")
    if pos>0 and pos<size-1:    
        print("Value : {}\tPosition : {}\tNeighbours : {}".format(A[pos], pos, A[pos-1:pos+2]))
    elif pos == 0:
        print("Value : {}\tPosition : {}\tNeighbours : {}".format(A[pos], pos, A[pos:pos+2]))
    elif pos == size - 1:
        print("Value : {}\tPosition : {}\tNeighbours : {}".format(A[pos], pos, A[pos-1:pos+1]))
    print("----------------------------------------------------------")

if __name__ == "__main__":
    main()