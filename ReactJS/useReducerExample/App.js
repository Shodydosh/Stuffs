import './App.css'
import { useState, useMemo, useReducer, useRef } from 'react'

// init state
const initState = {
    task: '',
    tasksList: []
}

//actions
const SET_TASK = 'set_task'
const ADD_TASK = 'add_task'
const REMOVE_TASK = 'remove_task'

const setTask = payload => {
    return {
        type: SET_TASK,
        payload
    }
}

const addTask = payload => {
    return {
        type: ADD_TASK,
        payload
    }
}

const removeTask = payload => {
    return {
        type: REMOVE_TASK,
        payload
    }
}

// reducer
const reducer = (state, action) => {

    // console.log(action);
    // console.log("prev state: " + state);

    let newState;

    switch (action.type) {
        case SET_TASK:
            newState = {
                ...state,
                task: action.payload
            }
            break;
        case ADD_TASK:
            newState = {
                ...state,
                tasksList: [...state.tasksList, action.payload]
            }
            break;
        case REMOVE_TASK:
            const newTasksList = [...state.tasksList]

            newTasksList.splice(action.payload, 1)

            newState = {
                ...state,
                tasksList: newTasksList
            }
            break
        default:
            throw new Error(`Invalid action ${action.type}`)
    }

    console.log(newState);

    return newState;
}


const App = () => {

    const [state, dispatch] = useReducer(reducer, initState);

    const { task, tasksList } = state

    const inputRef = useRef();

    const submitHandler = () => {
        if (task === '') {
            alert("please enter the name of the task!!");
            inputRef.current.focus()
            return;
        }

        dispatch(addTask(task));
        dispatch(setTask(''));

        inputRef.current.focus()
    }

    return (
        <div style={{ padding: '30px' }}>
            <h1> Todo App </h1>

            <input
                ref={inputRef}
                className='bg-white shadow-md rounded px-8 pt-6 pb-8 mb-4'
                value={task}
                placeholder='enter task'
                onChange={e => {
                    dispatch(setTask(e.target.value));
                }}
            />

            <button
                type="submit"
                className='bg-blue-500 hover:bg-blue-700 text-white font-bold px-8 pt-6 pb-8 m-4 rounded focus:outline-none focus:shadow-outline'
                onClick={submitHandler}
            > Add </button>

            <ul>
                {tasksList.map((task, index) => (
                    <li key={index} >
                        <div
                            key={index}
                            style={{ display: 'flex' }}
                            className="flex items-stretch max-w-sm rounded overflow-hidden shadow-lg">
                            <div className="px-6 py-4">
                                <div className="font-bold text-xl mb-2">{task}</div>
                                <p className="text-gray-700 text-sm">
                                    task added!
                                </p>
                            </div>
                            <div
                                style={{}}
                                className="px-6 py-4">
                                <button
                                    onClick={() => dispatch(removeTask(index))}
                                    className='focus:outline-none text-white bg-red-700 hover:bg-red-800 focus:ring-4 focus:ring-red-300 font-medium rounded-lg text-sm px-5 py-2.5 mr-2 mb-2 dark:bg-red-600 dark:hover:bg-red-700 dark:focus:ring-red-900'
                                >

                                    Delete
                                </button>
                            </div>
                        </div>

                    </li>
                ))}
            </ul>
        </div >
    )
}
export default App;