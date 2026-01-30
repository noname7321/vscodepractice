import helpers
helpers.display("This is a helper function.")

import helpers as hp
hp.display("This is a helper function using alias.")

from helpers import display
display("This is a helper function imported directly.")

from helpers import display as show
show("This is a helper function imported with alias.")

from helpers import *
display("This is a helper function imported using wildcard.")