class ProductOfNumbers {
    vector<int> a{1};

public:
    void add(int x) {
        if (x != 0) {
            a.push_back(x * a.back());
        } else {
            a.clear();
            a.push_back(1);
        }
    }

    int getProduct(int k) {
        return k < a.size() ? a.back() / a[a.size() - k - 1] : 0;
    }
};