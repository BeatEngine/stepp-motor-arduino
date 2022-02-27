class StepperController
{
  int a1;
  int a2;
  int b1;
  int b2;
  
  int pos;
  int totalSteps;


  void setStep()
  {
    if(pos % 4 == 1)
    {
      //Step 1
      analogWrite(a2, 0);
      analogWrite(b2, 0);
      analogWrite(a1, 1024);
      analogWrite(b1, 1024);
    }
    else if(pos % 4 == 2)
    {
      //Step 2
      analogWrite(a1, 0);
      analogWrite(b2, 0);
      analogWrite(a2, 1024);
      analogWrite(b1, 1024);
    }
    else if(pos % 4 == 3)
    {
      //Step 3
      analogWrite(a1, 0);
      analogWrite(b1, 0);
      analogWrite(a2, 1024);
      analogWrite(b2, 1024);
    }
    else if(pos % 4 == 0)
    {
      //Step 4
      analogWrite(a2, 0);
      analogWrite(b1, 0);
      analogWrite(a1, 1024);
      analogWrite(b2, 1024);
    }
  }

  /**
   * Halfstepp
   */
  void setStepFor(int steptime)
  {
    if(pos % 4 == 1)
    {
      //Step 1
      analogWrite(a2, 0);
      analogWrite(b2, 0);
      analogWrite(a1, 1024);
      analogWrite(b1, 0);
      delayMicroseconds(steptime);
      analogWrite(a2, 0);
      analogWrite(b2, 0);
      analogWrite(a1, 1024);
      analogWrite(b1, 1024);
      
    }
    else if(pos % 4 == 2)
    {
      //Step 2
      analogWrite(a1, 0);
      analogWrite(b2, 0);
      analogWrite(a2, 0);
      analogWrite(b1, 1024);
      delayMicroseconds(steptime);
      analogWrite(a1, 0);
      analogWrite(b2, 0);
      analogWrite(a2, 1024);
      analogWrite(b1, 1024);
      
    }
    else if(pos % 4 == 3)
    {
      //Step 3
      analogWrite(a1, 0);
      analogWrite(b1, 0);
      analogWrite(a2, 1024);
      analogWrite(b2, 0);
      delayMicroseconds(steptime);
      analogWrite(a1, 0);
      analogWrite(b1, 0);
      analogWrite(a2, 1024);
      analogWrite(b2, 1024);
    }
    else if(pos % 4 == 0)
    {
      //Step 4
      analogWrite(a2, 0);
      analogWrite(b1, 0);
      analogWrite(a1, 0);
      analogWrite(b2, 1024);
      delayMicroseconds(steptime);
      analogWrite(a2, 0);
      analogWrite(b1, 0);
      analogWrite(a1, 1024);
      analogWrite(b2, 1024);
    }
  }

    /**
   * Halfstepp
   */
  void setStepBack(int steptime)
  {
    if(pos % 4 == 1)
    {
      //Step 1
      analogWrite(a2, 0);
      analogWrite(b2, 0);
      analogWrite(a1, 1024);
      analogWrite(b1, 1024);
      delayMicroseconds(steptime);
      analogWrite(a2, 0);
      analogWrite(b2, 0);
      analogWrite(a1, 1024);
      analogWrite(b1, 0);
    }
    else if(pos % 4 == 2)
    {
      //Step 2
      analogWrite(a1, 0);
      analogWrite(b2, 0);
      analogWrite(a2, 1024);
      analogWrite(b1, 1024);
      delayMicroseconds(steptime);
      
      analogWrite(a1, 0);
      analogWrite(b2, 0);
      analogWrite(a2, 0);
      analogWrite(b1, 1024);
    }
    else if(pos % 4 == 3)
    {
      //Step 3
      analogWrite(a1, 0);
      analogWrite(b1, 0);
      analogWrite(a2, 1024);
      analogWrite(b2, 1024);
      delayMicroseconds(steptime);
      
      analogWrite(a1, 0);
      analogWrite(b1, 0);
      analogWrite(a2, 1024);
      analogWrite(b2, 0);
    }
    else if(pos % 4 == 0)
    {
      //Step 4
      
      analogWrite(a2, 0);
      analogWrite(b1, 0);
      analogWrite(a1, 1024);
      analogWrite(b2, 1024);
      delayMicroseconds(steptime);
      analogWrite(a2, 0);
      analogWrite(b1, 0);
      analogWrite(a1, 0);
      analogWrite(b2, 1024);
    }
  }
  
  public:

  StepperController(int pinA1, int pinA2, int pinB1, int pinB2, int steps)
  {
    pos = 1;
    a1 = pinA1;
    a2 = pinA2;
    b1 = pinB1;
    b2 = pinB2;
    totalSteps = steps;
    analogWrite(a1, 0);
    analogWrite(b1, 0);
    analogWrite(a2, 0);
    analogWrite(b2, 0);
  }

  /**
  * One Step forward
  */
  void forward()
  {
    setStep();
    pos++;
    if(pos > totalSteps)
    {
      pos -= totalSteps;
    }
  }
  /**
  * One Step backward
  */
  void backward()
  {
    setStep();
    pos--;
    if(pos <= 0)
    {
      pos += totalSteps;
    }
  }

  /**
  * One Step forward
  */
  void forward(int steptime)
  {
    setStepFor(steptime);
    pos++;
    if(pos > totalSteps)
    {
      pos -= totalSteps;
    }
  }
  /**
  * One Step backward
  */
  void backward(int steptime)
  {
    setStepBack(steptime);
    pos--;
    if(pos <= 0)
    {
      pos += totalSteps;
    }
  }

  
};
