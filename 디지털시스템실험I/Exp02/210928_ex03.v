module stimcret;
  reg a, b, c;
  wire f;
  Exp5 cwd(f, a, b, c);
  initial
   begin
      a = 1'b0;  b = 1'b0;  c = 1'b0;
    #80
      a = 1'b0;  b = 1'b0;  c = 1'b1;
    #80
      a = 1'b0;  b = 1'b1;  c = 1'b1;
    #80
      a = 1'b0;  b = 1'b1;  c = 1'b1;
    #80
      a = 1'b1;  b = 1'b0;  c = 1'b0;
    #80
      a = 1'b1;  b = 1'b0;  c = 1'b0;
    #80
      a = 1'b1;  b = 1'b1;  c = 1'b1;
    #80
      a = 1'b1;  b = 1'b1;  c = 1'b1;
    #80
    $finish;
  end
endmodule


module Exp5(f, a, b, c);
       input a, b, c;
       output f;
       reg f;
       always @ (a or b or c)
         case({a, b, c})
           3'b000:f = 1'b0;
           3'b001:f = 1'b1;
           3'b010:f = 1'b1;
           3'b011:f = 1'b1;
           3'b100:f = 1'b0;
           3'b101:f = 1'b0;
           3'b110:f = 1'b1;
           3'b111:f = 1'b1;     
         endcase                                                                                                            
endmodule

