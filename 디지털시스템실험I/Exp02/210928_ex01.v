module stimcret;
  reg A, B;
  wire x;
  my_NOR cwd(A, B, x);
  initial
   begin
      A = 1'b1;  B = 1'b1;
    #80
      A = 1'b0;  B = 1'b1;
    #80
      A = 1'b0;  B = 1'b0;
    #80
    $finish;
  end
endmodule


module my_NOR(A, B, x);
       input A, B;
       output x;
       wire e,f;
       nand #(10) G1(e, A, A);
       nand #(10) G2(f, B, B);
       nand #(10) G3(x ,e, f);
       nand #(10) G4(Q, x, x);            
endmodule
