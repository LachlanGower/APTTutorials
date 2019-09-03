typedef double& DblRef;

class Example {
  public:
    Example(double value);

    void setValue(DblRef value);
    double getValue();

    private:
      double* ptrValue;
    };
