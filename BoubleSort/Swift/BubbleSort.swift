extension Array where Element: Comparable {

func bubbleSort() -> Array<Element> {
                
        //check for trivial case
        guard self.count > 1 else {
            return self
        }
                
        //mutated copy
        var output: Array<Element> = self        
        
        for primaryIndex in 0..<self.count {                        
            let passes = (output.count - 1) - primaryIndex
                        
            //"half-open" range operator
            for secondaryIndex in 0..<passes {                
                let key = output[secondaryIndex]                                
                
                //compare / swap positions
                if (key > output[secondaryIndex + 1]) {
                  output.swapAt(secondaryIndex, secondaryIndex + 1)
                }
            }
        }
                
        return output        
    }
}

//para utilizar:
//let results: Array<Int> = numberList.bubbleSort()
