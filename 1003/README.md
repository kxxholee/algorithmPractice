# 1003 피보나치 함수

| 메모리  | 시간 | 
|--------|-----|
| 2020KB | 4ms |

주어진 `fibonacci()` 함수는 다음과 같다.

```cpp
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
```

어떤 자연수 `n` 을 위 함수의 입력으로 넣었을 때, 출력되는 0의 개수를 `an` , 출력되는 1의 개수를 `bn` 이라고 하면.  
 `n`을 `an`과 `bn`의 순서쌍으로 `n = (an, bn)`과 같이 나타낼 수 있다.  
 이때, `an` 은 `a0 = 1`이고 `a1 = 0`인 피보나치 수열이고, 마찬가지로 `bn`은 `b0 = 0`, `b1 = 1`인 피보나치 수열이다.

각 자연수에 대해서 `an`과 `bn`만을 출력해 주면 된다. 

