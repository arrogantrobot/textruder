Textruder
===========

Textruder is a tool for extruding text through patterns. The patterns currently baked into this project are produced by a [one-dimensional cellular automaton](http://archetyp.al/cellular-automata-rule-explorer "cellular automaton"). Any input text may be used, either from a file or from stdin.

Build it
==========

git clone git@github.com:arrogantrobot/textruder.git

cd textruder

cmake .

make

done!

Use it
=========

with input from a file

./textruder -i my_text_file.txt

or from stdin

yes | ./textruder

The default width matches the terminal. This may be overridden:

yes | ./textruder -w 20

Example Output
========


                                        a                                        
                                       a g                                      
                                      g   c                                     
                                     a t g g                                    
                                    t       g                                   
                                   g t     t c                                  
                                  a   t   g   c                                 
                                 c t g t a a t t                                
                                c               c                               
                               a a             c a                              
                              g   t           t   t                             
                             g g g a         g g c c                            
                            a       a       g       g                           
                           c a     g g     c a     g a                          
                          t   a   a   c   t   t   g   a                         
                         g g t c a g g a a t t c g a g a                        
                        c                               c                       
                       a g                             c c                      
                      t   g                           g   c                     
                     c a a c                         a g a g                    
                    t       g                       a       a                   
                   a c     c c                     t c     t c                  
                  t   c   t   a                   c   t   a   a                 
                 a a a t a c a a                 a a a t t a g g                
                c               c               a               g               
               g a             g t             g a             t g              
              g   c           t   c           a   c           g   c             
             c t g t         g a t c         c c a g         c a c t            
            t       t       g       a       g       a       g       g           
           c c     g a     g g     c g     g g     t a     g a     t c          
          a   c   c   t   g   a   g   g   t   c   a   g   g   a   g   t         
         t t g a g a c c a g c c t a a c c a a c a t a g g g a a a c c c
