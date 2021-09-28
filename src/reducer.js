
const initialState = {
 value: false
}

export default (state = initialState, action) => {
    switch (action.type) {
        case "TOGGLE":
            if(!state.value){
                state.value = true 
            }
            else{
                state.value= false
            }
            state = {
               ...state
            }
            break
        }
        return state
}