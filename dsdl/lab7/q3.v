module q3(b,x);
    input [3:0] b;
    output [3:0] x;
    wire [2:0] s;
    assign s = {b[2],b[1],b[0]};

    m81 stage0({~b[3],~b[3],~b[3],1'b0,1'b0,1'b0,b[3],b[3]},s,x[3]);
    m81 stage1({1'b0,1'b0,1'b0,~b[3],~b[3],~b[3],1'b1,1'b0},s,x[2]);
    m81 stage2({~b[3],1'b0,1'b0,~b[3],~b[3],1'b0,1'b0,1'b1},s,x[1]);
    m81 stage3({1'b0,~b[3],1'b0,~b[3],1'b0,~b[3],1'b0,1'b1},s,x[0]);
endmodule

module m81(w,s,f);
    input [7:0] w;
    input [2:0] s;
    output f;
    reg f;
    always @(w or s)
    case (s)
        0: f = w[0];
        1: f = w[1];
        2: f = w[2];
        3: f = w[3];
        4: f = w[4];
        5: f = w[5];
        6: f = w[6];
        7: f = w[7];         
    endcase
endmodule
