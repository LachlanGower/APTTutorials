int main(void){
  return 0;
}
class Universe(){
  public Universe(double x){
    this->lives = x;
    this->life = true;
  }
  public void setResources(double x){
    this->resources = x;
  }

  public void setLife(boolean x){
    this->life = x;
  }
  public double correction(){
    return lives/2;
  }


  public double* resources;
  public boolean uncheckedLife = true;
  public boolean* life;
  public int* lives;
}
//it’s a simple calculus. This universe is finite. Its resources, finite. If life is left unchecked, life will cease to exist. It needs correction.
double aSimpleCalculus(double lives){
  Universe universe = new Universe(lives);
  universe.setResources(finite);
  if(universe.isLifeUnchecked())
    universe.setLife(false);
  return universe.correction();
}
