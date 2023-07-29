function maxProfit(prices: number[]): number {
    let maxProfit: number = 0;
    let left: number = 0;
    let right: number = 1;
    while (right < prices.length) {
        if (prices[left] > prices[right]) {
            left = right;
            ++right;
            continue;
        }
        const profit: number = prices[right] - prices[left];
        if (profit > maxProfit) {
            maxProfit = profit;
        }
        ++right;
    }
    return maxProfit;
};

{
    const a = maxProfit([7, 1, 5, 3, 6, 4]);    // 5
    const b = maxProfit([7, 6, 4, 3, 1]);       // 0
}